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

  .btn {
  border: 2px solid black;
  background-color: white;
  color: black;
  padding: 14px 28px;
  font-size: 16px;
  cursor: pointer;
}

/* Green */
.success {
  border-color: #04AA6D;
  color: green;
}
  
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
     
  <td><button class = 'btn off' id='Motor'
     onclick = 'sendData(id)'>Press to turn MOTOR ON
     </button></td>

  <button class= 'btn success' onclick= 'updateByAJAX_Current()'> Tank1 level</button>
   <div id='Current'></div>
     
</tr></table>
<script> 

function updateByAJAX_Current(){
      const xhttp=new XMLHttpRequest();
      xhttp.onload=function(){
        document.getElementById("Current").innerText=this.responseText;
      }
      
      xhttp.open("GET", "http://localhost/iotinhtdocs/midsemproject/iotMidsemProject/getlastTank1.php?");
      xhttp.send();
}

function sendData(butn)
{
  var URL, variab, text;
  if(butn == 'Motor')
  {
    URL = 'LEDRurl';
    variab = 'LEDR';
  }

  if(butn == 'manual')
{
 URL = 'manualurl';
  variab = 'manualState';
    
 }


  if(butn == 'Motor')  
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