//
//  CCCollectionViewDataSource.h
//  CCCollectionView
//
//  Created by zysun on 14-3-16.
//
//

#ifndef CCCollectionView_CCCollectionViewDataSource_h
#define CCCollectionView_CCCollectionViewDataSource_h

#include "CCGeometry.h"

class CollectionViewCell;
class CollectionView;

/**
 *  brief 定义集合视图的数据源协议
 */
class CollectionViewDataSource
{
public:
    
    /**
     *  brief 为集合视图指定的位置设定单元格
     *
     *  @param collection 要设定单元格的集合视图
     *  @param idx        要设定单元格的下标
     *
     *  @return 要设定的单元格
     */
    virtual CollectionViewCell* collectionCellAtIndex(CollectionView* collection, ssize_t idx) = 0;
    
    /**
     *  brief 为集合视图设定单元格的数量
     *
     *  @param collection 要设定的集合试图
     *
     *  @return 要设定的单元格数量
     */
    virtual ssize_t numberOfCellsInCollection(CollectionView* collection) = 0;
};

#endif
