# -*- coding: utf-8 -*-
"""
Created on Mon Jul  5 20:18:11 2021

@author: ray95
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

path = 'D:/google drive/cpp/Data/'
start = 0
end = 99
step = 1
particle_num = 50

def read_txt(path, particle_num):
    F0 = pd.read_csv(path, index_col=False)
    FArr = np.array(F0)
    # print(FArr)
    
    Index1 = np.zeros(particle_num)
    Index2 = np.zeros(particle_num)
    Index3 = np.zeros(particle_num)

    FIndexArr = []
    for i in range (len(FArr)):
        for j in FArr[i]:
            FIndex = j.split()
            FIndexArr.append(FIndex)

    for k in range (len(FIndexArr)):
        Index1[k] = FIndexArr[k][0]
        Index2[k] = FIndexArr[k][1]
        Index3[k] = FIndexArr[k][2]

    return Index1,Index2, Index3

fig, ax = plt.subplots(1,1)

def updater(i):
    ax.cla()
    #ax[1].cla()
    #ax[2].cla()
    f_read = path + str(i) + '.txt'
    x_new, y_new, U_old= read_txt(f_read, particle_num)
    # print(x_new)
    
    #divider = make_axes_locatable(ax[0])
    #cax = divider.append_axes('right', size='5%', pad=0.5)
    ax.scatter(x_new,y_new,s = 100.0)
    #ax[0].set_xlim(0, 50)
    #ax[0].set_ylim(0, box_y_width)
    #ax[0].set_aspect('equal')
    #ax[0].set_xlabel('x position')
    #ax[0].set_ylabel('y position')
    #ax[0].set_title('10004box1min_0.8ci 0th-50th                Unit: um')
    #fig.colorbar(a0, cax=cax, orientation='vertical')
    
    #divider = make_axes_locatable(ax[1])
    #cax = divider.append_axes('right', size='5%', pad=0.5)
    #a1 = ax[1].scatter(x,y,c = (fx*fx+fy*fy)**0.5,s = 80.0, vmin=1.0e-5,vmax=5.0e-3)
    #ax[1].set_xlim(25, 75)
    #ax[1].set_ylim(0, box_y_width)
    #ax[1].set_aspect('equal')
    #ax[1].set_xlabel('x position')
    #ax[1].set_ylabel('y position')
    #ax[1].set_title('10004box1min_0.8ci 25th-75th                Unit: um')
    #fig.colorbar(a1, cax=cax, orientation='vertical')

    #divider = make_axes_locatable(ax[2])
    #cax = divider.append_axes('right', size='5%', pad=0.5)
    #a2 = ax[2].scatter(x,y,c = (fx*fx+fy*fy)**0.5,s = 80.0, vmin=1.0e-5,vmax=5.0e-3)
    #ax[2].set_xlim(50,100)
    #ax[2].set_ylim(0, box_y_width)
    #ax[2].set_aspect('equal')
    #ax[2].set_xlabel('x position')
    #ax[2].set_ylabel('y position')
    #ax[2].set_title('10004box1min_0.8ci 50th-100th                Unit: um')
    #fig.colorbar(a2, cax=cax, orientation='vertical')
    
anim = animation.FuncAnimation(fig, updater, frames = end+step, interval = 100, repeat = 2)

#anim.save('/home/motorsgroup/lammps-2021May22/lmp_test/problempic/bd_p.gif')

plt.show()

#%%
plt_arr = []
for i in range (end+step):
    f_read = path + str(i) + '.txt'
    x_new, y_new, U_old = read_txt(f_read, particle_num)
    plt_arr.append(U_old.sum())
plt.semilogy(np.arange(99), plt_arr[1::])

#%%

idx = np.round(np.linspace(1, len(cell1) - 1, 300)).astype(int) # 等間隔取數組
