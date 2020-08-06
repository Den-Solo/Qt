#ifndef MATHPARSER_H
#define MATHPARSER_H

#include "mathobject.h"

#include <QString>
#include <stack>

namespace SciMath {


    class MathParser
    {

    private:
        size_t pos_ = 0;
        std::stack<QChar> parenthesis_;

    public:
        MathParser();
        MathObject *Parse(const QString& eq);

    private:
        MathObject *Parse(size_t pos);
    };

}

#endif // MATHPARSER_H
