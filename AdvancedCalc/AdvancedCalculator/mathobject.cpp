#include "mathobject.h"

using namespace  SciMath;


double Number::exec() {
    return val;
}

double Add::exec() {
    return lval->exec() + rval->exec();
}

double Sub::exec() {
    return lval->exec() - rval->exec();
}

double Mult::exec() {
    return lval->exec() * rval->exec();
}

double Div::exec() {
    return lval->exec() / rval->exec();
}

double Mod::exec() {
    return static_cast<int64_t>(lval->exec()) % static_cast<int64_t>(rval->exec());
}

double Power::exec() {
    return std::pow(val->exec(),power->exec());
}

double Route::exec() {
    return std::pow(val->exec(), double(1) / power->exec());
}

double Abs::exec() {
    return std::abs(val->exec());
}
