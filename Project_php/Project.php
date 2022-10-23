<?php
require "db_set.php"

$con = mysqli_connect($servername,$username,$password,$dbname); 

echo $Water_level=$_GET['Water_level']. "<br/>";                //or POST or PUT

$sql = "INSERT INTO level_reading (Tank_ID, Water_level) VALUES ((SELECT Tank_ID FROM tank_information WHERE Location ='Rooftop'), '{$Water_level}')";  
//$sql = "INSERT INTO level_reading (Tank_ID, Water_level) VALUES ((SELECT Tank_ID FROM tank_information WHERE Location ='Charlotte'), '{$Water_level}')";     

if (mysqli_query($con, $sql)) {
echo "New record created successfully";
} else {
echo "Unsuccessful";
}


?>