TEMPLATE = app
CONFIG += console c++11
QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    src/main.cpp \
    include/node.cpp \
    include/edge.cpp \
    include/graph.cpp \
    include/dijkstra.cpp \
    include/extended_dijkstra.cpp \
    include/relaxed_node_selection.cpp \
    include/bellman_ford.cpp \
    include/floyd_warshall.cpp \
    include/astar.cpp

HEADERS += \
    include/node.hpp \
    include/edge.hpp \
    include/graph.hpp \
    include/dijkstra.hpp \
    include/extended_dijkstra.hpp \
    include/hashfunction.hpp \
    include/relaxed_node_selection.hpp \
    include/bellman_ford.hpp \
    include/floyd_warshall.hpp \
    include/astar.hpp
