#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: alainlegall
"""

import cv2
import numpy as np
import matplotlib.pyplot as plt

def apply_convolution(image_path):
    # Charger l'image en niveaux de gris
    image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)
    
    if image is None:
        print("Erreur : Impossible de charger l'image.")
        return
    
    # Définir le noyau flouteur 3x3
    kernel = np.array([[1, 1, 1],
                       [1, 1, 1],
                       [1, 1, 1]], dtype=np.float32) / 9.0
    
    # Appliquer la convolution avec OpenCV
    blurred_image = cv2.filter2D(image, -1, kernel)
    
    # Afficher les images originale et filtrée
    plt.figure(figsize=(10, 5))
    
    plt.subplot(1, 2, 1)
    plt.imshow(image, cmap='gray')
    plt.title("Image Originale")
    plt.axis("off")
    
    plt.subplot(1, 2, 2)
    plt.imshow(blurred_image, cmap='gray')
    plt.title("Image Floutée")
    plt.axis("off")
    
    plt.show()
    
# Exemple d'utilisation
demo_image_path = 'zuper_image.png'
apply_convolution(demo_image_path)
