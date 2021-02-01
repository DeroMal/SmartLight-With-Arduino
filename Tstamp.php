<?php $dt = date_create(); // Current Time - Sunday, 3 May 2020 16:57:47 GMT+01:00 DST
// echo date_timestamp_get($dt);
// time();
// $x=25;
date_default_timezone_set('Africa/Kampala');
$x=$_GET["x"];
$time = date('H:i:s');
// echo $time;
// echo '<p></p>';
if($x>=100){
    if(strtotime($time)>=strtotime('18:30:00') and strtotime($time) <= strtotime('23:59:59')){
        //do some work
        echo "1";
    }
    else if(strtotime($time)>=strtotime('00:00:00') and strtotime($time) < strtotime('07:00:00')){
        //do some work
        echo "1";
    }
    else if(strtotime($time)>=strtotime('07:00:00') and strtotime($time) < strtotime('18:30:00')){
        //do some work
        echo "0";
    }
    else{
        // echo strtodate($time);
    echo strtotime($time)."<p>".date('H:i:sa')."</p>";
    }
    // echo strtodate($time);
    // echo "<p>".date('H:i:s')."</p>";
}
else{
    if(strtotime($time)>=strtotime('18:30:00') and strtotime($time) <= strtotime('23:59:59')){
        //do some work
        echo "1";
    }
    else if(strtotime($time)>=strtotime('00:00:00') and strtotime($time) < strtotime('07:00:00')){
        //do some work
        echo "1";
    }
    else if(strtotime($time)>=strtotime('07:00:00') and strtotime($time) < strtotime('18:30:00')){
        //do some work
        echo "0";
    }
    else{
        // echo strtodate($time);
    echo strtotime($time)."<p>".date('H:i:sa')."</p>";
    }
    // echo strtodate($time);
    // echo "<p>".date('H:i:s')."</p>";
}

?>