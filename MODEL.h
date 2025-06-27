#ifndef MODEL_H
#define MODEL_H

#include "SETTINGS.h"

/*
Base class for all prediction models.
*/
class Model {
public:
    // = 0: this function MUST be implemented for child classes 
    virtual void train() = 0;
    virtual void predict() const = 0;
    virtual ~Model();

private:


};

/*
ModelFactory handles instantiation of model type
*/
class ModelFactory {
    static unique_ptr<Model> create(const string& type) {

    }
};


#endif