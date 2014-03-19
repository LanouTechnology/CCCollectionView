//
//  CCCollectionViewCell.h
//  CCCollectionView
//
//  Created by zysun on 14-3-16.
//
//

#ifndef __CCCollectionView__CCCollectionViewCell__
#define __CCCollectionView__CCCollectionViewCell__

#include "extensions/ExtensionMacros.h"
#include "cocos2d.h"

USING_NS_CC;

class CollectionViewCell: public Node
{
public:
    CollectionViewCell();
    ~CollectionViewCell();
    
    static CollectionViewCell* create(const char* fileName);
    bool init(const char* fileName);
    
    ssize_t getIdx() const;
    void setIdx(ssize_t uIdx);
    void reset();

    Sprite* getImageView();
private:
    ssize_t _idx;
    Sprite* _imageView;
    
    /**
     *  brief 设置要显示的图片
     *
     *  @param fileName 要显示的图片的名字
     */
    void setImageViewWithFile(const char* fileName);
};

#endif /* defined(__CCCollectionView__CCCollectionViewCell__) */
