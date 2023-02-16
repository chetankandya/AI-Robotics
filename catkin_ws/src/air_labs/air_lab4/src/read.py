#!/usr/bin/env python3

# import pandas as pd
# import plotly.express as px

# df = pd.read_csv('/home/cheka108/TDDE05/catkin_ws/src/air_labs/air_lab4/reward.csv') 

# fig = px.line(df, x = 'Episodes', y = 'Rewards', title='Cumuliative rewards')
# fig.show()


import csv
import matplotlib.pyplot as plt
  
x = []
y = []
  
with open('/home/cheka108/TDDE05/catkin_ws/src/air_labs/air_lab4/q_table/reards_ql.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        x.append(row[0])
        y.append(float(row[1]))
  
plt.plot(range(0, 118, 1), y, color = 'g', linestyle = 'dashed',
         marker = 'o',label = "Rewards")
  
plt.xlabel('Episodes')
plt.ylabel('Epsilon')
plt.title('Epsilon per episode', fontsize = 20)
plt.grid()
plt.legend()
plt.show()
