//
// Created by Ivan Stoynev on 12.11.24.
//

#ifndef FACTORY_H
#define FACTORY_H
#include "Figure.h"

class Factory {
public:
    virtual std::unique_ptr<Figure> create() = 0;
    virtual ~Factory() = default;
};

#endif //FACTORY_H