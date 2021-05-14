//
// Created by liron on 14/05/2021.
//

#include "CarFreshModels.h"

CarFreshModels::CarFreshModels(int typeID, int num_of_models) : typeID(typeID), num_of_models(num_of_models),
                                                                lowest_unsold_model(0), left_array(nullptr),
                                                                right_array(nullptr), top(nullptr), right(nullptr),
                                                                left(nullptr), height(0) {
    left_array = new int[num_of_models];
    right_array = new int[num_of_models];
    for (int i = 0; i < num_of_models; i++) {
        left_array[i] = i - 1;
        right_array[i] = i + 1;
    }

}

CarFreshModels::~CarFreshModels() {
    delete[] left_array;
    delete[] right_array;
}

CarFreshModels::CarFreshModels(const CarFreshModels &car_fresh) : typeID(car_fresh.typeID),
                                                                  num_of_models(car_fresh.num_of_models),
                                                                  lowest_unsold_model(car_fresh.lowest_unsold_model),
                                                                  left_array(nullptr),
                                                                  right_array(nullptr), top(car_fresh.top),
                                                                  right(car_fresh.right),
                                                                  left(car_fresh.left), height(car_fresh.height) {
    left_array = new int[num_of_models];
    right_array = new int[num_of_models];
    for (int i = 0; i < num_of_models; i++) {
        left_array[i] = car_fresh.left_array[i];
        right_array[i] = car_fresh.right_array[i];
    }
}

CarFreshModels& CarFreshModels::operator=(const CarFreshModels &car_fresh){
    if (this == &car_fresh){
        return *this;
    }
    delete[] left_array;
    delete [] right_array;
    left_array = new int[num_of_models];
    right_array = new int[num_of_models];
    top = car_fresh.top;
    right = car_fresh.right;
    left = car_fresh.left;
    height = car_fresh.height;
    typeID = car_fresh.typeID;
    num_of_models = car_fresh.num_of_models;
    lowest_unsold_model = car_fresh.lowest_unsold_model;
    for (int i = 0; i < num_of_models; i++) {
        left_array[i] = car_fresh.left_array[i];
        right_array[i] = car_fresh.right_array[i];
    }
    return *this;
}

bool CarFreshModels::removeModel(int model){
    //we need to check if model is in range and not sold yet before we enter this function.
    //because we check before in the array of CarType
    if (model == lowest_unsold_model){ //if its the lowest model
        lowest_unsold_model = right_array[lowest_unsold_model];
        if(lowest_unsold_model != num_of_models){
            left_array[right_array[model]] = left_array[model]; //will be -1
        }
    }

    else{
        right_array[left_array[model]] = right_array[model];
        if (right_array[model] != num_of_models){
            left_array[right_array[model]] = left_array[model];
        }
    }

    if (lowest_unsold_model == num_of_models){
        return true; //meaning we sold all models of this typeID.
    }

    return false;
}

bool CarFreshModels::operator==(const CarFreshModels &car_fresh){
    if(typeID == car_fresh.typeID) {
        return true;
    }
    return false;
}

bool CarFreshModels::operator<(const CarFreshModels& car_fresh){
    if(typeID < car_fresh.typeID){
        return true;
    }
    return false;
}

/*void CarFreshModels::print(){

}*/