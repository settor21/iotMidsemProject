/**
 * based on code by Niel Cameron
 * this page forms the text for the HTML
 * Now it is one continous piece because there are no variables
 * Store array (page) data in flash (program) memory instead of SRAM, 
 * qualifeid by the PROGMEM modifier.
 * R"()" is a raw literal string.
 * 
 * This page is returned to client, on the client side, the javascript will
 * execute. THe JS/AJAX code is at end of the file
 */



char page[] PROGMEM = R"(
  <!DOCTYPE html><html><head>
  <title>Local network</title>
  <style>
  
  .on {background-color:red}
  .off {background-color:blue}
  </style></head>
  <body>
  <h1>ESP32 as server, but also connects to web</h1>
  <p> Working in STA mode </p>
  
  <table style='width:100%'><tr>
  <td>Green LED is <span id='LEDG'>OFF</span> now</td>
  <td>Red LED is <span id='LEDR'>OFF</span> now</td>
  </tr></table>
  
  <table style='width:100%'><tr>
  <td><button class = 'btn off' id='Green LED'
       onclick = 'sendData(id)'>Press to turn Green LED ON
       </button></td>
       <td><button class = 'btn off' id='Red LED'
     onclick = 'sendData(id)'>Press to turn Red LED ON
     </button></td>
</tr></table>
<p>Counter is <span id='counter'>0</span> now</p>
<button class = 'btn zero' id = 'zero'
     onclick = 'sendData(id)'>Press to zero counter</button>

<div id="extText"> </div>
     
<script>
function sendData(butn)
{
  var URL, variab, text;
  if(butn == 'Red LED')
  {
    URL = 'LEDRurl';
    variab = 'LEDR';
  }
  else if(butn == 'Green LED')
  {
    URL = 'LEDGurl';
    variab = 'LEDG';
  }
  else if(butn == 'zero')
  {
    URL = 'zeroUrl';
    variab = 'counter';
  }
  if(butn == 'Red LED' || butn == 'Green LED')
{ // change button class and text 
  var state = document.getElementById(butn).className;
  state = (state == 'btn on' ? 'btn off' : 'btn on');
  text = (state == 'btn on' ? butn + ' OFF' : butn + ' ON');
    document.getElementById(butn).className = state;
    document.getElementById(butn).innerHTML = 'Press to turn ' + text;
  }
  var xhr = new XMLHttpRequest();
  xhr.onload = function(){
    document.getElementById(variab).innerHTML = this.responseText;
  }
  xhr.open('GET', URL, true);
  xhr.send();
}


<!-- not needed, but enables periodic update of count -->
/**
 * based on code by Niel Cameron
 * this page forms the text for the HTML
 * Now it is one continous piece because there are no variables
 * Store array (page) data in flash (program) memory instead of SRAM, 
 * qualifeid by the PROGMEM modifier.
 * R"()" is a raw literal string.
 * 
 * This page is returned to client, on the client side, the javascript will
 * execute. THe JS/AJAX code is at end of the file
 */



char page[] PROGMEM = R"(
  <!DOCTYPE html><html><head>
  <title>Local network</title>
  <style>
  body {margin-top:50px; font-family:Arial}
  body {font-size:20px; text-align:center}
  .btn {display:block; width:280px; margin:auto; padding:30px}
  .btn {font-size:30px; color:black; text-decoration:none}
  .on {background-color:SkyBlue}
  .off {background-color:LightSteelBlue}
  .zero {background-color:Thistle}
  td {font-size:30px; margin-top:50px; margin-bottom:5px}
  p {font-size:30px; margin-top:50px; margin-bottom:5px}
  </style></head>
  <body>
  <h1>ESP32 local area network</h1>
  <table style='width:100%'><tr>
  <td>Green LED is <span id='LEDG'>OFF</span> now</td>
  <td>Red LED is <span id='LEDR'>OFF</span> now</td>
  </tr></table>
  <table style='width:100%'><tr>
  <td><button class = 'btn off' id='Green LED'
       onclick = 'sendData(id)'>Press to turn Green LED ON
       </button></td>
       <td><button class = 'btn off' id='Red LED'
     onclick = 'sendData(id)'>Press to turn Red LED ON
     </button></td>
</tr></table>
<p>Counter is <span id='counter'>0</span> now</p>
<button class = 'btn zero' id = 'zero'
     onclick = 'sendData(id)'>Press to zero counter</button>
<script>
function sendData(butn)
{
  var URL, variab, text;
  if(butn == 'Red LED')
  {
    URL = 'LEDRurl';
    variab = 'LEDR';
  }
  else if(butn == 'Green LED')
  {
    URL = 'LEDGurl';
    variab = 'LEDG';
  }
  else if(butn == 'zero')
  {
    URL = 'zeroUrl';
    variab = 'counter';
  }
  if(butn == 'Red LED' || butn == 'Green LED')
{ // change button class and text 
  var state = document.getElementById(butn).className;
  state = (state == 'btn on' ? 'btn off' : 'btn on');
  text = (state == 'btn on' ? butn + ' OFF' : butn + ' ON');
    document.getElementById(butn).className = state;
    document.getElementById(butn).innerHTML = 'Press to turn ' + text;
  }
  var xhr = new XMLHttpRequest();
  xhr.onreadystatechange = function(butn)
  {
    if (this.readyState == 4 && this.status == 200)
    document.getElementById(variab).innerHTML = this.
    responseText;
  };
  xhr.open('GET', URL, true);
  xhr.send();
}

<!-- not needed, but enables periodic update of count -->
setInterval(reload, 1000);
function reload()
{
  var xhr = new XMLHttpRequest();
  xhr.onreadystatechange = function()
  {
    if(this.readyState == 4 && this.status == 200)
    document.getElementById('counter').innerHTML = this.
    responseText;
  };
  xhr.open('GET', 'countUrl', true);
  xhr.send();
}
</script>
</body></html>
)";
