//
//  CCCollectionViewDelegate.h
//  CCCollectionView
//
//  Created by zysun on 14-3-16.
//
//

#ifndef CCCollectionView_CCCollectionViewDelegate_h
#define CCCollectionView_CCCollectionViewDelegate_h

#include "GUI/CCScrollView/CCScrollView.h"

class CollectionViewCell;
class CollectionView;

/**
 *  brief 定义集合视图样式和行为的协议
 */
class CollectionViewDelegate: public cocos2d::extension::ScrollViewDelegate
{
public:
    /**
     *  brief 单元格被点击要执行的方法
     *
     *  @param collection 被点击的集合视图
     *  @param cell       被点击的单元格
     */
    virtual void collectionCellTouched(CollectionView* collection, CollectionViewCell* cell) = 0;
    /**
     *  brief 单元格刚被点击时要执行的方法
     *
     *  @param collection 被点击的集合视图
     *  @param cell       被点击的单元格
     */
    virtual void collectionCellHighlight(CollectionView* collection, CollectionViewCell* cell){};
    /**
     *  brief 手指即将离开单元格时要执行的方法
     *
     *  @param collection 要离开的集合视图
     *  @param cell       要离开的单元格
     */
    virtual void collectionCellUnhighlight(CollectionView* collection, CollectionViewCell* cell){};
    //和单元格样式相关的应该在delegate中写，而不应该在dataSource中写。
    //dataSource定义的都是和数据层相关的接口
    /**
     *  brief 设定单元格的尺寸,默认返回{0,0}
     *
     *  @param collection 要设定的集合视图
     *  @param idx        要设定的单元格下标
     *
     *  @return 设定的尺寸
     */
    virtual cocos2d::Size collectionCellSizeForIndex(CollectionView* collection, ssize_t idx){
        return cellSizeForCollection(collection);
    };
    /**
     *  brief 为集合视图中所有的单元格设定尺寸
     *
     *  @param collection 要设定的集合视图
     *
     *  @return 设定的尺寸
     */
    virtual cocos2d::Size cellSizeForCollection(CollectionView* collection) {
        return cocos2d::Size::ZERO;
    };
    /**
     *  brief 最左侧单元格和左边界的间距
     *
     *  @param collection 要设置的集合视图
     *
     *  @return 设定的间距
     */
    virtual float leftSideSpaceForCollection(CollectionView* collection){return 0;}
    /**
     *  brief 最上层单元格和上边界的间距
     *
     *  @param collection 要设置的集合视图
     *
     *  @return 设定的间距
     */
    virtual float upSideSpaceForCollection(CollectionView* collection){return 0;}
    /**
     *  brief 单元格即将进入重用队列
     *
     *  @param collection 集合视图
     *  @param cell       即将进入重用队列的单元格
     */
    virtual void collectionCellWillRecycle(CollectionView* collection, CollectionViewCell* cell){};

};

#endif
