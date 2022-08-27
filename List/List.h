#ifndef LIST_H
#define LIST_H

template<typename type>
class List{
private:
    void operator=(const List &){}
    List(const List &){}
public:
    List(){}
    virtual ~List(){}
    virtual void clear() = 0;
    virtual void insert(const type &item) = 0;
    virtual void append(const type &item) = 0;
    virtual type remove() = 0;
    virtual void moveToStart() = 0;
    virtual void moveToEnd() = 0;
    virtual void prev() = 0;
    virtual void next() = 0;
    virtual int length() = 0;
    virtual int currPos() = 0;
    virtual void moveToPos(int pos) = 0;
    virtual type getValue() = 0;
    virtual int Search(const type& item) = 0;
};

#endif