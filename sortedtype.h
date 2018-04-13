#ifndef SORTEDTYPE_H_INCLUDED
#define SORTEDTYPE_H_INCLUDED

template <class ItemType, class ItemType2, class ItemType3, class ItemType4>
class SortedType{
    struct NodeType{
        ItemType name;
        ItemType2 phone;
        ItemType3 email;
        ItemType4 address;
        char important;
        NodeType* next;
    };
    public:
        SortedType();
        ~SortedType();
        bool IsFull();
        int LengthIs();
        void MakeEmpty();
        void RetrieveItem(ItemType);
        void CheckForSimilarName(ItemType, bool&);
        void CheckForSimilarNumber(ItemType2, bool&);
        void InsertItem(ItemType, ItemType2, ItemType3, ItemType4, char);
        void DeleteItem(ItemType2);
        void ResetList();
        void GetNextItem(ItemType&, ItemType2&, ItemType3&, ItemType4&, char&);
        void PrintFavoriteList();
        void PrintList();
    private:
        NodeType* listData;
        int length;
        NodeType* currentPos;
};

#endif // SORTEDTYPE_H_INCLUDED
