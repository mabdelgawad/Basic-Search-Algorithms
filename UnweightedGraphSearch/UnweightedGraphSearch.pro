TEMPLATE = app
CONFIG += console c++11
QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    src/main.cpp \
    include/node.cpp \
    include/edge.cpp \
    include/graph.cpp \
    include/breadthfirstsearch.cpp \
    include/depthfirstsearch.cpp

HEADERS += \
    include/node.hpp \
    include/edge.hpp \
    include/graph.hpp \
    include/breadthfirstsearch.hpp \
    include/depthfirstsearch.hpp \
    include/hashfunction.hpp
