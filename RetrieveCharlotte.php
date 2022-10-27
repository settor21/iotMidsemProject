<?php
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "storagetank_level";

    $con = mysqli_connect($servername,$username,$password,$dbname);
    
    $data=array(); 
   // $q=mysqli_query($con,"SELECT * FROM level_reading");

   $q=mysqli_query($con,"SELECT * FROM (
  SELECT * 
  FROM level_reading 
  WHERE (Tank_ID = 2)  ORDER BY Reading_ID DESC LIMIT 5
) AS `table` ORDER by Reading_ID ASC");    

    $row=mysqli_fetch_object($q);
    while ($row)
    {         
        echo "{$row->Water_level} {$row->Time}\n\n\n";
        $row=mysqli_fetch_object($q);
    }       
   
?>