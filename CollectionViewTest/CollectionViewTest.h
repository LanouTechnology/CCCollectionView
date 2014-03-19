//
//  CollectionViewTest.h
//  CCCollectionView
//
//  Created by zysun on 14-3-16.
//
//

#ifndef __CCCollectionView__CollectionViewTest__
#define __CCCollectionView__CollectionViewTest__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

#include "CCCollectionView/CCCollectionView.h"

USING_NS_CC_EXT;

class CollectionViewTest : public cocos2d::Layer, public CollectionViewDelegate, public CollectionViewDataSource
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
        
    CREATE_FUNC(CollectionViewTest);
    
    virtual void scrollViewDidScroll(ScrollView* view) {};
    virtual void scrollViewDidZoom(ScrollView* view) {}
    virtual void collectionCellTouched(CollectionView* table, CollectionViewCell* cell);
    virtual cocos2d::Size collectionCellSizeForIndex(CollectionView *table, ssize_t idx);
    virtual CollectionViewCell* collectionCellAtIndex(CollectionView *table, ssize_t idx);
    virtual ssize_t numberOfCellsInCollection(CollectionView *table);
    virtual float leftSideSpaceForCollection(CollectionView* collection);
    virtual float upSideSpaceForCollection(CollectionView* collection);

};


#endif /* defined(__CCCollectionView__CollectionViewTest__) */
