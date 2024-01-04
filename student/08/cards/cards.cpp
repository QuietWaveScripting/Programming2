#include "cards.hh"

// TODO: Implement the methods here

Cards::Cards():
    top_(nullptr)
{

}

Card_data *Cards::get_topmost()
{
    return top_;
}

void Cards::add(int id)
{
    // create a new card
    Card_data *new_card = new Card_data{id, top_};
    top_ = new_card;
}

void Cards::print_from_top_to_bottom(std::ostream &s)
{
    // remm to use s as output stream


    // go through the list till gotten to the bottom of cards
    Card_data *current =top_;
    int index = 1;
    while(current != nullptr){
        s << index++ << ": " << current->data << std::endl;
        current = current->next;
    }
}

bool Cards::remove(int &id)
{
    // check if empty
    if (top_ == nullptr){
        return false;
    }
    Card_data *temp = top_;
    top_ = top_->next;
    // "return" int value
    id = temp->data;
    delete temp;
    return true;
}

bool Cards::bottom_to_top()
{
    if(top_ == nullptr){
        return false;
    }
    if(top_->next == nullptr){
        return true;
    }

    //find the 2nd to last card
    Card_data *second_last = nullptr;
    Card_data *last = top_;
    while(last->next != nullptr){
        second_last = last;
        last = last->next;
    }
    // last should be last card of deck

    second_last->next = nullptr;
    last->next = top_;
    top_= last;
    return true;
}

bool Cards::top_to_bottom()
{
    if(top_ == nullptr){
        return false;
    }

    // check if only one card
    if(top_->next == nullptr){
        return true;
    }

    //find last
    Card_data *last = top_;
    while(last->next !=nullptr){
        last = last->next;
    }
    Card_data *temp = top_->next;
    last->next = top_;
    top_->next = nullptr;
    top_ = temp;
    return true;
}

void Cards::print_from_bottom_to_top(std::ostream &s)
{
    recursive_print(top_, s);
}

Cards::~Cards()
{
    // loop through linked list deleting unnecessary pointers
    Card_data *current = top_;
    while(current != nullptr){
        top_= top_->next;
        delete current;
        current = top_;
    }
}

int Cards::recursive_print(Card_data *top, std::ostream &s)
{
    int index = 1;
    // end condition = we are at the bottom of deck
    // first go to bottom, then print
    if (top -> next != nullptr){
        index += recursive_print(top->next, s);
    }

    s << index << ": " << top->data << std::endl;
    return index;
}

