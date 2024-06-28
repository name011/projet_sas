<?php
$targetDir = __DIR__. '/'; // Chemin vers le répertoire où sera stocker les images

// Vérifie si la requête est de type POST pour télécharger ou supprimer une image
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Vérifie si le fichier doit être téléchargé
    if (isset($_FILES['image']['tmp_name']) && !empty($_FILES['image']['tmp_name'])) {
        $targetFile = $targetDir . basename($_FILES["image"]["name"]);
        $uploadOk = 1;
        $imageFileType = strtolower(pathinfo($targetFile, PATHINFO_EXTENSION));

        // Vérifie si le fichier est une image
        $check = getimagesize($_FILES["image"]["tmp_name"]);
        if($check !== false) {
            $uploadOk = 1;
        } else {
            echo "Le fichier n'est pas une image.";
            $uploadOk = 0;
        }
        if($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg") {
            echo "Seuls les formats JPG, PNG et JPEG sont autorisés.";
            $uploadOk = 0;
        }
        if (file_exists($targetFile)) {
            echo "Le fichier existe déjà.";
            $uploadOk = 0;
        }
        if ($_FILES["image"]["size"] > 150000) {
            echo "Le fichier est trop volumineux.";
            $uploadOk = 0;
        }
        if ($uploadOk == 0) {
            echo "Le fichier n'a pas été téléchargé.";
        } else {
            if (move_uploaded_file($_FILES["image"]["tmp_name"], $targetFile)) {
                echo "Le fichier ". basename($_FILES["image"]["name"]). " a été téléchargé.";
            } else {
                echo "Une erreur s'est produite lors du téléchargement du fichier.";
            }
        }
    } 
    elseif (isset($_POST['delete']) && !empty($_POST['delete'])) {
        $fileToDelete = basename($_POST['delete']); 
        $targetFile = $targetDir . $fileToDelete; 

        if (file_exists($targetFile)) {
            if (unlink($targetFile)) {
                echo "Le fichier ". $fileToDelete . " a été supprimé.";
            } else {
                echo "Une erreur s'est produite lors de la suppression du fichier.";
            }
        } else {
            echo "Le fichier n'existe pas.";
        }
    } else {
        echo "Aucun fichier n'a été supprimé.";
    }
} else {
    echo "Aucune image n'a été téléchargée ou supprimée.";
}
?>
