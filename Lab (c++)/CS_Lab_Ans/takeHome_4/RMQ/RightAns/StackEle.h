#ifndef stackele_h
#define stackele_h

class StackEle{

public:
    int pos; int num;

	StackEle(){pos = 0;}
    
    StackEle(int pos, int num) {
        this->pos = pos;
        this->num = num;
    }
};

#endif