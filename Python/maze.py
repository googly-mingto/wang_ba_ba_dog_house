from node import *
import numpy as np
import csv
import pandas
from enum import IntEnum
import math


class Action(IntEnum):
    ADVANCE = 1
    U_TURN = 2
    TURN_RIGHT = 3
    TURN_LEFT = 4
    HALT = 5


class Maze:
    def __init__(self, filepath):
        # TODO : read file and implement a data structure you like
        self.raw_data = pandas.read_csv(filepath).values
        #self.nodes = []
        self.nd_dict = dict()  # key: index, value: the correspond node
        for i in range(np.shape(self.raw_data)[0]):
            self.nd_dict[i+1] = Node(i+1)
            for element in self.raw_data[i][1:5]:
                if not np.isnan(element):
                    for index in np.where(self.raw_data[i][1:5] == element):
                        self.nd_dict[i+1].setSuccessor(int(element), index+1, 2)
        """
        self.nd_array = np.array([Node(i+1) for i in range(np.shape(self.raw_data)[0])])
        for i in range(np.shape(self.raw_data)[0]):
            for element in self.raw_data[i][1:5]:
                if not np.isnan(element):
                    for index in np.where(self.raw_data[i][1:5] == element):
                        self.nd_array[i].setSuccessor(int(element), index+1, 2)
        """

    def getStartPoint(self):
        if (len(self.nd_dict) < 2):
            print("Error: the start point is not included.")
            return 0
        return self.nd_dict[1]

    def getNodeDict(self):
        return self.nd_dict

    def BFS(self, nd):
        # TODO : design your data structure here for your algorithm
        # Tips : return a sequence of nodes from the node to the nearest unexplored deadend
        return None

    def BFS_2(self, nd_from, nd_to):
        # TODO : similar to BFS but fixed start point and end point
        # Tips : return a sequence of nodes of the shortest path
        queue = [nd_from]
        #0:white 1:gray 2:black
        color_dict = dict()
        d_dict = dict()
        pre_dict = dict()

        #initialization : set all nd is white , distance is infinite, and predecessor is -1 
        for key in self.nd_dict:
            color_dict[key] = 0
            d_dict[key] = 1000000
            pre_dict[key] = -1

        d_dict[nd_from] = 0
        color_dict[nd_from] = 1

        while queue != []:
            for succ in self.nd_dict[queue[0]].Successors:
                if color_dict[succ[0]] == 0:
                    color_dict[succ[0]] += 1
                    d_dict[succ[0]] = d_dict[queue[0]] + 1
                    pre_dict[succ[0]] = queue[0]
                    queue.append(succ[0])
            color_dict[queue[0]] += 1
            queue.pop(0)
        result = [nd_to]
        temp = nd_to
        while result[-1] != nd_from:
            result.append(pre_dict[temp])
            temp = pre_dict[temp]
        result.pop()
        result.reverse()
        return result

    def getAction(self, car_dir, nd_from, nd_to):
        # TODO : get the car action
        # Tips : return an action and the next direction of the car
        return None

    def strategy(self, nd):
        return self.BFS(nd)

    def strategy_2(self, nd_from, nd_to):
        return self.BFS_2(nd_from, nd_to)
if __name__ == '__main__':
    test = Maze("data/small_maze.csv")
    print(test.strategy_2(4, 2))