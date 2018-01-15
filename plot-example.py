from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import pandas as pd

# initialize mplot3d
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# get data from xlsx
xlsx = pd.ExcelFile('screensaver.xlsx')
df = pd.read_excel(xlsx, 'level')

xs = df['pos_x'].tolist()
ys = df['pos_y'].tolist()
zs = df['pos_z'].tolist()

ax.scatter(xs, ys, zs=zs, depthshade=False)

plt.show()
