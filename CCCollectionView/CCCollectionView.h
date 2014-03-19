//
//  CCCollectionView.h
//  CCCollectionView
//
//  Created by zysun on 14-3-16.
//
//

#ifndef __CCCollectionView__CCCollectionView__
#define __CCCollectionView__CCCollectionView__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "CCCollectionViewCell.h"

#include <set>
#include <vector>

#include "CCCollectionViewDelegate.h"
#include "CCCollectionViewDataSource.h"

USING_NS_CC;
USING_NS_CC_EXT;

/**
 *  brief 集合视图
 */
class CollectionView: public ScrollView, public ScrollViewDelegate
{
public:
    CollectionView();
    virtual ~CollectionView();
    
    /**
     *  brief 创建一个空的集合视图
     *
     *  @return 创建后的集合视图
     */
    static CollectionView* create();
    /**
     *  brief 用指定的数据源和尺寸创建集合视图
     *
     *  @param dataSource 指定的数据源
     *  @param size       指定的尺寸
     *
     *  @return 创建后的集合视图
     */
    static CollectionView* create(CollectionViewDataSource* dataSource, CollectionViewDelegate* delegate, Size size);
    /**
     *  brief 用指定的数据源、尺寸和容器创建一个集合视图
     *
     *  @param dataSrouce 指定的数据源
     *  @param size       指定的尺寸
     *  @param container  指定的容器
     *
     *  @return 创建后的集合视图
     */
    static CollectionView* create(CollectionViewDataSource* dataSrouce, CollectionViewDelegate* delegate, Size size, Node *container);
    /**
     *  brief 用指定的尺寸和容器初始化集合视图
     *
     *  @param size      指定的尺寸
     *  @param container 指定的容器
     *
     *  @return 初始化结果
     */
    bool initWithViewSize(Size size, Node* container = NULL);
    /**
     *  brief 为集合视图指定数据源
     *
     *  @param source 指定的数据源
     */
    void setDataSource(CollectionViewDataSource* dataSource);
    /**
     *  brief 获取集合视图的数据源
     *
     *  @return 集合视图的数据源
     */
    CollectionViewDataSource* getDataSource() {return _dataSource;}
    /**
     *  brief 为集合视图指定委托对象
     *
     *  @param delegate 指定的委托对象
     */
    void setDelegate(CollectionViewDelegate* delegate);
    /**
     *  brief 获取集合视图的委托对象
     *
     *  @return 集合视图的委托对象
     */
    CollectionViewDelegate* getDelegate() {return _delegate;}
    /**
     *  brief 更新指定位置的单元格
     *
     *  @param idx 要更新的单元格的位置
     */
    void updateCellAtIndex(ssize_t idx);
    /**
     *  brief 在指定位置插入单元格
     *
     *  @param idx 单元格要插入的位置
     */
    void insertCellAtIndex(ssize_t idx);
    /**
     *  brief 删除指定位置的单元格
     *
     *  @param idx 要删除的单元格的位置
     */
    void removeCellAtIndex(ssize_t idx);
    /**
     *  brief 重新加载数据
     */
    void reloadData();
    /**
     *  brief 从重用队列中获取一个单元格
     *
     *  @return 从重用队列中取出的单元格
     */
    CollectionViewCell* dequeueCell();
    /**
     *  brief 获取指定位置的单元格
     *
     *  @param idx 要获取的位置
     *
     *  @return 指定位置的单元格
     */
    CollectionViewCell *cellAtIndex(ssize_t idx);
    /**
     *  brief 设置背景图片
     *
     *  @param fileName 背景图片的名称
     */
    void setBackGroundViewWithFile(const char* fileName);
    /**
     *  brief 设置是否开启多选
     *
     *  @param flag true or false
     */
    void setMultipleSelectEnabled(bool flag);
    /**
     *  brief 获取是否开启了多选
     *
     *  @return true or false
     */
    bool getMultipleSelectEnabled(){return _multipleTouchEnabled;};
    /**
     *  brief 获取所有被选择的单元格的下标
     *
     *  @return 所有被选择的单元格的下标
     */
    std::set<ssize_t>* getSelectedIndices(){return _selectedIndices;};
    
    // Overrides
    virtual void scrollViewDidScroll(ScrollView* view) override;
    virtual void scrollViewDidZoom(ScrollView* view)  override {}
    virtual bool onTouchBegan(Touch *pTouch, Event *pEvent) override;
    virtual void onTouchMoved(Touch *pTouch, Event *pEvent) override;
    virtual void onTouchEnded(Touch *pTouch, Event *pEvent) override;
    virtual void onTouchCancelled(Touch *pTouch, Event *pEvent) override;
private:
    void _updateCellPositions();
    void _updateContentSize();

    long __indexFromOffset(Point offset);
    long _indexFromOffset(Point offset);
    Point __offsetFromIndex(ssize_t index);
    Point _offsetFromIndex(ssize_t index);

    void _moveCellOutOfSight(CollectionViewCell *cell);
    void _setIndexForCell(ssize_t index, CollectionViewCell *cell);
    void _addCellIfNecessary(CollectionViewCell * cell);
    //获取被点击的单元格的下标
    ssize_t _getIndexWithTouchPoint(Point point);

    Direction _oldDirection;

    //委托对象
    CollectionViewDelegate* _delegate;
    //数据源
    CollectionViewDataSource* _dataSource;
    //背景视图
    Sprite* _backgroundView;
    //行数
    ssize_t _row;
    //列数
    ssize_t _col;
    //最左侧单元格和左边界的间距
    float _leftSpace;
    //最上层单元格和上边界的间距
    float _upSpace;
    //单元格之间的纵向间距
    float _verticalSpace;
    //单元格之间的水平间距
    float _horizonalSpace;
    //正在点击的单元格
    CollectionViewCell* _touchedCell;
    //所有的单元格下标
    std::set<ssize_t>* _indices;
    //所有单元格的位置
    std::vector<Point> _vCellsPositions;

    //正在使用的单元格
    Vector<CollectionViewCell*> _cellsUsed;
    //重用队列中的单元格
    Vector<CollectionViewCell*> _cellsFreed;

    //是否开启多选
    bool _multipleTouchEnabled;
    //在开启多选的情况下，存储所有被选中的单元格。
    std::set<ssize_t>* _selectedIndices;
    __Array *_cellsSelected;
    
    bool _isUsedCellsDirty;
};

#endif /* defined(__CCCollectionView__CCCollectionView__) */
