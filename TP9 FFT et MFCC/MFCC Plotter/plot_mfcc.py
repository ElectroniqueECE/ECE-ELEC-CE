# %%
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm

# Define the desired MFCC size
n_mfcc = 13 # Number of MFCC coefficients

# Load MFCC coefficients from text file
mfcc_path = 'mel.txt'
mfcc_coeffs = np.loadtxt(mfcc_path)

# Reshape the coefficients to the desired size
n_frames = mfcc_coeffs.shape[0] // n_mfcc
mfcc_coeffs = mfcc_coeffs[:n_mfcc * n_frames].reshape(n_frames, n_mfcc)

# Transpose the array to invert the axes
mfcc_coeffs = mfcc_coeffs.T

# Plot MFCC with inverted axes
plt.figure(figsize=(10, 4))
plt.imshow(mfcc_coeffs, cmap=cm.coolwarm, origin='lower', aspect='auto')
plt.title('MFCC Graph over time')
plt.xlabel('Time')
plt.ylabel('MFCC ')
plt.tight_layout()
plt.show()
# %%
