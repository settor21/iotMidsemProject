<?php
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "storagetank_level";

    $con = mysqli_connect($servername,$username,$password,$dbname);
    
    $data=array(); 
   // $q=mysqli_query($con,"SELECT * FROM level_reading");

   $sql = "SELECT * FROM level_reading  WHERE (Tank_ID = 2)  ORDER BY Reading_ID DESC LIMIT 1";
 
   if ($q=mysqli_query($con, $sql)) {
    while ($row = $q->fetch_assoc()){
        echo "{$row['Water_level']}  {$row['Time']} \n\n\n"; //"<br/>";
    }
   } 
   
?>