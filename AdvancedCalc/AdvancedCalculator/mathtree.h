#ifndef MATHTREE_H
#define MATHTREE_H


#include "mathparser.h"
#include "mathobject.h"

#include <memory>


namespace SciMath {


    class MathTree
    {
    public:
        MathTree(const QString& str);
        double eval();
    private:
        std::unique_ptr<MathObject> route_;
        MathParser parser_;
    };


}

#endif // MATHTREE_H
