from enum import IntEnum

class Direction(IntEnum):
    NORTH = 1
    SOUTH = 2
    WEST  = 3
    EAST  = 4

# Successor : (Node, direction to node, distance)
class Node:
    def __init__(self, index=0):
        self.index = index
        # store successor as (Node, direction to node, distance)
        self.Successors = [] #--->adjacency list

    def getIndex(self):
        return self.index

    def getSuccessors(self):
        return self.Successors

    def setSuccessor(self, successor, direction, length=1):
        self.Successors.append((successor, Direction(direction), int(length)))
        print("For Node {}, a successor {} is set.".format(self.index, self.Successors[-1]))
        return


    def getDirection(self, nd):
        # TODO : Return the direction of nd from the present node if nd is adjacent to the present node.
        for i in range(len(self.Successors)):
            if nd == self.Successors[i][0]:
                return Direction(self.Successors[i][1])
        print('Node'+ str(nd) + ' is not adjacent to Node' + str(self.index))

    def isSuccessor(self, nd):
        for succ in self.Successors:
            if succ[0] == nd: 
                return True
        return False

