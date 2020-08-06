#ifndef MATHOBJECT_H
#define MATHOBJECT_H


#include <memory>
#include <cmath>

namespace SciMath {



    class MathObject {

    public:
        virtual double exec() = 0;
        virtual ~MathObject() = default;

    };

    struct Number : public MathObject {
        double val;
        double exec() override;
    };

    struct Add: public MathObject {
        std::unique_ptr<MathObject> lval;
        std::unique_ptr<MathObject> rval;
        double exec() override;
    };

    struct Sub: public MathObject {
        std::unique_ptr<MathObject> lval;
        std::unique_ptr<MathObject> rval;
        double exec() override;
    };


    struct Mult: public MathObject {
        std::unique_ptr<MathObject> lval;
        std::unique_ptr<MathObject> rval;
        double exec() override;
    };


    struct Div: public MathObject {
        std::unique_ptr<MathObject> lval;
        std::unique_ptr<MathObject> rval;
        double exec() override;
    };

    struct Mod: public MathObject {
        std::unique_ptr<MathObject> lval;
        std::unique_ptr<MathObject> rval;
        double exec() override;
    };


    struct Power: public MathObject {
        std::unique_ptr<MathObject> val;
        std::unique_ptr<MathObject> power;
        double exec() override;
    };


    struct Route: public MathObject {
        std::unique_ptr<MathObject> val;
        std::unique_ptr<MathObject> power;
        double exec() override;
    };

    struct Abs: public MathObject {
        std::unique_ptr<MathObject> val;
        double exec() override;
    };

}
#endif // MATHOBJECT_H
