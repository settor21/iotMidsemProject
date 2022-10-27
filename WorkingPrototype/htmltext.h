char page[] PROGMEM = R"(
<!DOCTYPE html>
<html>
<head>
  <title>Monitoring Storage Tank Level</title>
  <style>
  .btn {display:block; width:200px; margin:auto; padding:10px}
  .btn {font-size:20px; color:black; text-decoration:none}
    .on {background-color:red}
    .off {background-color:blue}
  
    </style>
</head>
<body>
  <h1 style="color: blue;">Monitoring Storage Tank Level</h1>
  <h1 text-align= "center"> </h1>
  <p style="font-size: 120%;">This page allows user 
    to control motor for each tank in each house in Regimanuel Estate.</p>
  <body>


  <table style='width:100%'><tr>
  <td>Red LED is <span id='LEDR'>OFF</span> now</td>
  </tr></table>
  <table style='width:100%'><tr>

  <td><button class = 'btn off' id='manual'
     onclick = 'sendData(id)'>Press to enter manual operation
     </button></td>
     
  <td><button class = 'btn off' id='Red LED'
     onclick = 'sendData(id)'>Press to turn MOTOR ON
     </button></td>

     
</tr></table>
<script> 

function sendData(butn)
{
  var URL, variab, text;
  if(butn == 'Red LED')
  {
    URL = 'LEDRurl';
    variab = 'LEDR';
  }

  if(butn == 'manual')
{
 URL = 'manualurl';
  variab = 'manualState';
    
 }


  if(butn == 'Red LED')
{ // change button class and text 
  var state = document.getElementById(butn).className;
  state = (state == 'btn on' ? 'btn off' : 'btn on');
  text = (state == 'btn on' ? butn + 'OFF' : butn + ' ON');
    document.getElementById(butn).className = state;
    document.getElementById(butn).innerHTML = 'Press to turn ' + text;
  }
  var xhr = new XMLHttpRequest();
  xhr.onreadystatechange = function(butn)
  {
    if (this.readyState == 4 && this.status == 200)

//   xhr.onload = function(){
    document.getElementById(variab).innerHTML = this.responseText;
  };
  xhr.open('GET', URL, true);
  xhr.send();
}
</script>
</body></html>
)";