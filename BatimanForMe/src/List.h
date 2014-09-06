#pragma once

#include"stdafx.h"


template<class LType>
class List{

public:

    template<class EType>
    class Element {
    protected:
        Element<EType>* pNextElement;
        EType* pAttached;

    public:
        Element()
        {
            pNextElement = NULL;
        }

        ~Element() {}

        Element<EType>* getNextElement() const   {return pNextElement;}

        void setNextElement(Element<EType>* pElement) {pNextElement = pElement;}

        void setAttached(EType* pAtt) {pAttached = pAtt;}
        EType* getAttached() const {return pAttached;}

    };

protected:
	Element<LType>* pFirstElement;
	Element<LType>* pLastElement;

    Element<LType>* pBefore;
    Element<LType>* pActual;

	int listSize;

public:
	List()
	{
        pFirstElement = NULL;
        pLastElement = NULL;
        listSize = 0;
	}
	~List()
	{
        pBefore = pFirstElement;
        pActual = pFirstElement;

        while(pBefore)
        {
            pActual = pBefore->getNextElement();
            delete pBefore->getAttached();
            delete pBefore;
            pBefore = pActual;
        }
	}

	const int getListSize() const
	{
	    return listSize;
	}

	void include(LType* pIn)
	{
        Element<LType>* pAux = new Element<LType>;
        pAux->setAttached(pIn);
        if(pFirstElement == NULL)
        {
            pFirstElement = pAux;
            pLastElement = pAux;
        }
        else
        {
            pLastElement->setNextElement(pAux);
            pLastElement = pAux;
        }
        listSize++;
	}

    void exclude(int position)
	{
	    if(position > listSize-1)

        {
            allegro_message("The position doesn't exist in this list");
            exit(1);
        }

        int index;

        pBefore = NULL;

        pActual = pFirstElement;


        for(index = 0; index < position; index++)
        {
            pBefore = pActual;
            pActual = pActual->getNextElement();
        }

        if(position == 0)
        {
            pFirstElement = pFirstElement->getNextElement();
        }
        else if(position == listSize-1)
        {
            pLastElement = pBefore;
        }

        if(listSize > 1 && position != 0)
        {
            pBefore->setNextElement(pActual->getNextElement());
        }



        delete pActual->getAttached();
        delete pActual;

        listSize--;
	}

	Element<LType>* getFirst() const
	{
	        return pFirstElement;
	}

	Element<LType>* getLast()
	{
	        return pLastElement;
	}

    LType* operator[] (const int elementIndex)
    {
        int index;
        Element<LType>* pAux = pFirstElement;
        for(index = 0; index < elementIndex; index++)
        {
            pAux = pAux->getNextElement();
        }
        return (pAux->getAttached());
    }

    void remove(LType* pIn)
    {
        int index;

        pBefore = NULL;

        pActual = pFirstElement;


        for(index = 0; pActual->getAttached() != pIn && index < listSize-1; index++)
        {
            pBefore = pActual;
            pActual = pActual->getNextElement();
        }

        if(index == 0)
        {
            pFirstElement = pFirstElement->getNextElement();
        }
        else if(index == listSize-1)
        {
            pLastElement = pBefore;
        }

        if(listSize > 1 && index != 0)
        {
            pBefore->setNextElement(pActual->getNextElement());
        }

        delete pActual;

        listSize--;
    }
};



