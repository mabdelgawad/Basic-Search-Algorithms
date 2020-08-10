/*
 * hashfunction.hpp file: Header file describes the hash
 * functions of unoredred sets and unordred maps ***
 * Created   : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */

#pragma once

#include "node.hpp"

namespace UnweightedGraphSearch {

//! Hash function class consists of on () operator that
//! return the hash code as size_t.

class myNodeHashFunction {

public:
    //! () operator is used to hash elements of a set/map
    std::size_t operator()(const Node& node) const {
        return static_cast<std::size_t>(node.getHashCode());
    }
};

} /* end of the name space */
