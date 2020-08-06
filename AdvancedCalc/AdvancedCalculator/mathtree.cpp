#include "mathtree.h"
#include <memory>

using namespace SciMath;

MathTree::MathTree(const QString& str)
{
    route_ = std::make_unique<MathObject>(parser_.Parse(str));
}

double MathTree::eval()
{
    return route_->exec();
}
