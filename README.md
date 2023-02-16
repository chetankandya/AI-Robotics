# TDDE05-AI-Robotics

This is my project for the course TDDE05 AI Robotics.The code related to the project is inside lab 4 folder.
The project is about achieving reactive obstacle avoidance in unknown environments using 3 approaches: Fixed window model, RL and DRL.

Nodes used for fixed window Model:
    fixed_window.py
    move_to_goal.py

Nodes used for fixed Reinforcement learning model Model:
    QLearn.py (Reinforcement learning implementation)
    q_explore.py (Training node)
    move_to_goal_ql.py (Uses the Q table to move to goal)

Nodes used for fixed Deep Reinforcement Learning Model:
    dqn.py (Deep Reinforcement learning implementation)
    dqn_learn.py (Training node)
