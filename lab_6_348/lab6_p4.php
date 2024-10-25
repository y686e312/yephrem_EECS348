<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Practice 4</title>
    <style>
        table {
            border: 3px solid black
        }
        th, td {
            border: 3px solid black;
            text-align: center;
        }
    </style>
</head>
<body>

<a href = "index.html">Home Page</a><br>

<h1 style="text-align: center;">PHP Multiplication Table</h1>

<form method="POST" style="text-align: center;">
    <label for="number">Enter a number for the table size </label>
    <input type="number" name="number" id="number" required>
    <button type="submit">Create Table</button>
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    
    $num = intval($_POST['number']);

    echo "<table>";
    
    echo "<tr><th></th>";  
    for ($i = 1; $i <= $num; $i++) {
        echo "<th>$i</th>";
    }
    echo "</tr>";

    for ($row = 1; $row <= $num; $row++) {
        echo "<tr>";
        echo "<th>$row</th>";  

        for ($col = 1; $col <= $num; $col++) {
            $result = $row * $col;
            echo "<td>$result</td>";
        }

        echo "</tr>";
    }

    echo "</table>";
}
?>

</body>
</html>
