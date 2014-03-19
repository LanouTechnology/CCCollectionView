//
//  CollectionViewTest.cpp
//  CCCollectionView
//
//  Created by zysun on 14-3-16.
//
//

#include "CollectionViewTest.h"

#define COLLECTIONVIEW_WIDHT 1024
#define COLLECTIONVIEW_HEIGHT 768

USING_NS_CC;

cocos2d::Scene* CollectionViewTest::createScene()
{
    Scene *scene = Scene::create();
    CollectionViewTest* collectionViewTest = CollectionViewTest::create();
    scene->addChild(collectionViewTest);
    return scene;
}

bool CollectionViewTest::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
	Size winSize = Director::getInstance()->getWinSize();
    
	CollectionView* collectionView = CollectionView::create(this,this,Size(COLLECTIONVIEW_WIDHT, COLLECTIONVIEW_HEIGHT));
    collectionView->setMultipleSelectEnabled(true);
	collectionView->setDirection(ScrollView::Direction::VERTICAL);
    collectionView->setAnchorPoint(Point(0.5f, 0.5f));
	collectionView->setPosition(Point(winSize.width*0.5f-COLLECTIONVIEW_WIDHT*0.5f, winSize.height*0.5f-COLLECTIONVIEW_HEIGHT*0.5f));
    collectionView->setBackGroundViewWithFile("natural_0.png");

	this->addChild(collectionView);
	collectionView->reloadData();
    return true;
}

#pragma mark - CollectionViewDelegate
void CollectionViewTest::collectionCellTouched(CollectionView* collection, CollectionViewCell* cell)
{
    CCLOG("cell touched at index: %ld", cell->getIdx());
    
    std::set<ssize_t>* selectedIndices = collection->getSelectedIndices();
    CCLOG("getSelectedIndices:");
    for(const ssize_t index : *selectedIndices)
    {
        CCLOG("%ld", index);
    }
}

Size CollectionViewTest::collectionCellSizeForIndex(CollectionView *collection, ssize_t idx)
{
    return Size(114, 114);
}

float CollectionViewTest::leftSideSpaceForCollection(CollectionView* collection)
{
    return 0;
}

float CollectionViewTest::upSideSpaceForCollection(CollectionView* collection)
{
    return 0;
}
#pragma mark - CollectionViewDataSource
CollectionViewCell* CollectionViewTest::collectionCellAtIndex(CollectionView *collection, ssize_t idx)
{
    auto string = String::createWithFormat("%ld", idx);
    CollectionViewCell *cell = collection->dequeueCell();
    if (!cell) {
        cell = CollectionViewCell::create("Icon.png");
        auto label = LabelTTF::create(string->getCString(), "Helvetica", 20.0);
        label->setPosition(Point::ZERO);
		label->setAnchorPoint(Point::ZERO);
        label->setTag(123);
        cell->addChild(label);
    }
    else
    {
        auto label = (LabelTTF*)cell->getChildByTag(123);
        label->setString(string->getCString());
    }
        return cell;
}

ssize_t CollectionViewTest::numberOfCellsInCollection(CollectionView *collection)
{
    return 40;
}
