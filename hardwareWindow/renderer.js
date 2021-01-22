console.log("Renderer activated");

const ipc = require('electron').ipcRenderer;
ipc.send('hardwareWindow','window1 ready');

var interval;



ipc.on('text_area_content', function(event, message){
  var text_area = document.getElementById('text_area');
  console.log(message)
  text_area.innerHTML = message;
});
var debug_area = document.getElementById('debug_area');
ipc.on('debug_area_content', function(event, message){
  console.log(message);
  if(message === "Port disconnected")
  {
    clearInterval(interval);
    }
  debug_area.innerHTML = message;
  var progress_bar = document.getElementById('progress_bar');
  progress_bar.value = 40;
});



var btn_save = document.getElementById('btn_save');
btn_save.addEventListener('click', function(){
  var text_area = document.getElementById('text_area');
  ipc.send('save', text_area.value);
});

var btn_compile = document.getElementById('btn_compile');
btn_compile.addEventListener('click', function(){
  var text_area = document.getElementById('text_area');
  ipc.send('save', text_area.value);
  ipc.send('compile',text_area.value);
  var progress_bar = document.getElementById('progress_bar');
  var j = 0;
  interval = setInterval(function(){ 
      j++; progress_bar.value = j;
      if(j >= 35){clearInterval(interval);}}
      , 1000);
});

var input_port = document.getElementById('input_port').value;
var btn_upload = document.getElementById('btn_upload');

btn_upload.addEventListener('click', function(){
  input_port = document.getElementById('input_port').value;
  ipc.send('input_port', input_port);
  ipc.send('upload','upload');
  var progress_bar = document.getElementById('progress_bar');
  var j = 0;
  interval = setInterval(function(){ 
      j++; progress_bar.value = j;
      if(j >= 35){clearInterval(interval);}}
      , 1000);
});
var btn_search_ports = document.getElementById('btn_search_ports');
btn_search_ports.addEventListener('click', function(){
  ipc.send('search_ports','search_ports');
});




