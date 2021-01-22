console.log("Renderer activated");

const ipc = require('electron').ipcRenderer;
ipc.send('mainWindow','mainWindow ready');


var btn_user_interface = document.getElementById('btn_user_interface');
btn_user_interface.addEventListener('click', function(){
  ipc.send('open user_interface', 'open user_interface');
});
var btn_hardware = document.getElementById('btn_hardware');
btn_hardware.addEventListener('click', function(){
  ipc.send('open hardware', 'open hardware');
});
var btn_software = document.getElementById('btn_software');
btn_software.addEventListener('click', function(){
  ipc.send('open software', 'open software');
});
