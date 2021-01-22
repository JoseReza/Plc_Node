var exec = require('child_process').exec; 
var fs = require('fs');
const {app, BrowserWindow, Menu} = require('electron');
const electron = require('electron');
const path = require('path');
var ipc = electron.ipcMain;

exec('cd node_modules/node-red && npm start');

function createWindows () { 

  const mainWindow = new BrowserWindow({width: 900, height: 400, x: 400, y: 200, 
   title: "Menu" ,icon: './icon.png', webPreferences: {nodeIntegration: true}});
  Menu.setApplicationMenu(null);
  mainWindow.setResizable(false);
  mainWindow.loadFile('mainWindow/mainWindow.html');
  mainWindow.on('page-title-updated', (evt) => {evt.preventDefault();});
}

app.whenReady().then(createWindows);
app.on('window-all-closed', function () {if (process.platform !== 'darwin') app.quit()});
app.on('activate', function () {if (BrowserWindow.getAllWindows().length === 0) createWindow()});





// IPC LISTENER

var input_port = "0";
var plc_rutine = "";

ipc.on('hardwareWindow', (event, args) => {
  console.log(args);
  var plc_rutine = fs.readFileSync('python/plc/rutine.h', 'utf-8');
  event.sender.send('text_area_content', plc_rutine); 
 });

 ipc.on('save', (event, args) => {
   console.log(args);
  plc_rutine = args;
  fs.writeFileSync('python/plc/rutine.h', plc_rutine);
  event.sender.send('debug_area_content', 'Saved'); 
 });

 ipc.on('compile', (event, args) => {
  console.log(args);
  plc_rutine = args;
  fs.writeFileSync('python/plc/rutine.h', args);
  console.log("Starting compiling...");
  exec('arduino-cli compile --fqbn esp32:esp32:esp32 python/plc/plc.ino',
  (err, stdout, stderr) => {
      if (err) {console.error(`exec error: ${err}`);return;}
      console.log(stdout);
      event.sender.send('debug_area_content', stdout); 
    });
  event.sender.send('debug_area_content', 'Compiling...'); 
 });

 ipc.on('input_port', (event, args) => {
  console.log(args);
  input_port = String(args);
 });

 ipc.on('upload', (event, args) => {
  console.log("Starting uploading...");
  exec('cd python && python esptool.py --port COM'+ input_port +' write_flash 0x1000 bootloader_dio_80m.bin  0x10000 plc/plc.ino.esp32.esp32.esp32.bin 0x8000 plc/plc.ino.esp32.esp32.esp32.partitions.bin',
  (err, stdout, stderr) => {
      if (err) {
        console.error(`exec error: ${err}`);
        event.sender.send('debug_area_content', 'Port disconnected'); 
      return;
    }
      console.log(stdout);
      event.sender.send('debug_area_content', "Uploaded!!"); 
    });
  event.sender.send('debug_area_content', 'Uploading...'); 
 });

 ipc.on('search_ports', (event, args) => {
  console.log("Searching ports...");
  exec('arduino-cli board list',
  (err, stdout, stderr) => {
      if (err) {console.error(`exec error: ${err}`);return;}
      console.log(stdout);
      event.sender.send('debug_area_content', stdout); 
    });
    event.sender.send('debug_area_content', 'Searching ports...'); 
 });
  
// IPC LISTENER WINDOWS

ipc.on('open user_interface', (event, args) => {
  const userInterfaceWindow = new BrowserWindow({width: 650,height: 800, x: 900, y: 0, 
    title:"User interface" ,icon: './icon.png'});
  userInterfaceWindow.setMenu(null);  
  userInterfaceWindow.loadURL('http://localhost:1880/ui');
  userInterfaceWindow.on('page-title-updated', (evt) => {evt.preventDefault();});
 });
 ipc.on('open software', (event, args) => {
  const softwareWindow = new BrowserWindow({width: 900,height: 300, x: 0,
    title:"Software programming",y: 0, icon: './icon.png'});
  softwareWindow.setMenu(null);
  softwareWindow.loadURL('http://localhost:1880');
  softwareWindow.on('page-title-updated', (evt) => {evt.preventDefault();});
});
ipc.on('open hardware', (event, args) => {
  const hardwareWindow = new BrowserWindow({width: 900, height: 500, x: 0, y: 300, 
    title:"Hardware programming",icon: './icon.png', webPreferences: {nodeIntegration: true}});
  Menu.setApplicationMenu(null);
  hardwareWindow.setResizable(false);
  hardwareWindow.loadFile('hardwareWindow/hardwareWindow.html');
  hardwareWindow.on('page-title-updated', (evt) => {evt.preventDefault();});
});