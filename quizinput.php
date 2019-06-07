<!DOCTYPE html>
<html>
  <head>
<link rel="stylesheet" type="text/css" href="quizlayout.css">
    <title>Form Input 2</title>
  </head>


  <body>

    <h1>This is the sports quiz game. Play, have fun, and try to get the highest score!</h1>
    <p>For each question, type in T for true and F for false</p>

    <?php
       // define variables and set to empty values
       $arg1 = $arg2 = $output = $retc = "";
       if ($_SERVER["REQUEST_METHOD"] == "POST") {
         $arg1 = test_input($_POST["arg1"]);
         $arg2 = test_input($_POST["arg2"]);
	$arg3 = test_input($_POST["arg3"]);
	$arg4 = test_input($_POST["arg4"]);
	$arg5 = test_input($_POST["arg5"]);
	$arg6 = test_input($_POST["arg6"]);
	$arg7 = test_input($_POST["arg7"]);
	$arg8 = test_input($_POST["arg8"]);
	$arg9 = test_input($_POST["arg9"]);
        $arg10 = test_input($_POST["arg10"]);
	exec("/usr/lib/cgi-bin/sp2b/quizcode " . $arg1 . " " . $arg2 . " " . $arg3 . " " . $arg4 . " " . $arg5 . " " . $arg6 . " " . $arg7 . " " . $arg8 . " " . $arg9 . " " . $arg10, $output, $retc); 
       }
       function test_input($data) {
         $data = trim($data);
         $data = stripslashes($data);
         $data = htmlspecialchars($data);
         return $data;
       }
    ?>

    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
      Q1 Ray Allen currently holds the record for most 3 pointers made: <input type="text" name="arg1"><br>
      Q2 The New England Patriots have won the most NFL championships: <input type="text" name="arg2"><br>
	Q3 Liverpool FC has the most Champions League titles in history: <input type="text" name="arg3"><br>
      Q4 Stephen Curry holds the record for most threes in NBA history: <input type="text" name="arg4"><br>
	Q5 LeBron James has three MVPs: <input type="text" name="arg5"><br>
      Q6 Jayson Tatum is only 20 years old: <input type="text" name="arg6"><br>
	Q7 Russell Westbrook shoots less than 40 percent from the field: <input type="text" name="arg7"><br>
      Q8 Ben Simmons is a two time Rookie of the Year: <input type="text" name="arg8"><br>
	Q9 The Clippers have made it to the Western Conference Finals: <input type="text" name="arg9"><br>
      Q10 Eli Manning is a quarterback in the NFL: <input type="text" name="arg10"><br>
      <br>
      <input type="submit" value="Go!">
    </form>

    <?php
       // only display if return code is numeric - i.e. exec has been called
       if (is_numeric($retc)) {
         echo "<h2>Your input:</h2>";
         echo $arg1;
         echo "<br>";
         echo $arg2;
         echo "<br>";
	echo $arg3;
         echo "<br>";
         echo $arg4;
         echo "<br>";
	echo $arg5;
         echo "<br>";
         echo $arg6;
         echo "<br>";
	echo $arg7;
         echo "<br>";
         echo $arg8;
         echo "<br>";
	echo $arg9;
         echo "<br>";
         echo $arg10;
         echo "<br>";       
         echo "<h2>Program Output (an array):</h2>";
         foreach ($output as $line) {
           echo $line;
           echo "<br>";
         }
       
         echo "<h2>Program Return Code:</h2>";
         echo $retc;
       }
    ?>
    
  </body>
</html>
