#include "queue.hh"
#include <iostream>

using namespace std;

Queue::Queue(unsigned int cycle):cycle_(cycle){

}

Queue::~Queue(){
    while(first_ != nullptr){
        Vehicle* vehicle_to_be_deleted = first_;
        first_ = first_->next;

        delete vehicle_to_be_deleted;
    }
}

void Queue::enqueue(const string& reg){
    if(is_green_){
        cout << "GREEN: The vehicle " << reg << " need not stop to wait" << endl;
    } else {
        Vehicle* new_vehicle = new Vehicle{reg, nullptr};

        if(first_ == nullptr){
            first_ = new_vehicle;
            last_ = new_vehicle;
        } else {
            last_->next = new_vehicle;
            last_ = new_vehicle;
        }
    }
}

bool Queue::dequeue(){
    if(first_ == nullptr){
        return false;
    }
    Vehicle* previous_first = first_;
    first_ = first_->next;
    delete previous_first;
    return true;
}

void Queue::switch_light(){
    if(is_green_){
        is_green_ = false;
        print();
    } else {
        is_green_ = true;
        print();
        unsigned int passing_vehicles = 0;
        while(passing_vehicles < cycle_){
            if(!dequeue()){
                break;
            }
            is_green_ = false;
            ++passing_vehicles;
        }
    }
}

void Queue::print() const{
    Vehicle* counter = first_;
    if(is_green_){
        if(first_ == nullptr){
            cout << "GREEN: No vehicles waiting in traffic lights" << endl;
        } else {
            cout << "GREEN: Vehicle(s) ";
            unsigned int passing_vehicles = 0;
            while(passing_vehicles < cycle_){
                if(counter != nullptr){
                    cout << counter->reg_num << " ";
                    counter = counter->next;
                    ++passing_vehicles;
                } else {
                    break;
                }
            }
            cout << "can go on" << endl;
        }
    } else {
        if(first_ == nullptr){
            cout << "RED: No vehicles waiting in traffic lights" << endl;
        } else {
            cout << "RED: Vehicle(s) ";
            while(counter != nullptr){
                cout << counter->reg_num << " ";
                counter = counter->next;
            }
            cout << "waiting in traffic lights" << endl;
        }
    }
}

void Queue::reset_cycle(unsigned int cycle){
    cycle_ = cycle;
}
