//
//  CCCollectionViewCell.cpp
//  CCCollectionView
//
//  Created by zysun on 14-3-15.
//
//

#include "CCCollectionViewCell.h"

CollectionViewCell::CollectionViewCell()
{
    _imageView = Sprite::create();
    this->addChild(_imageView);
    _imageView->retain();
}

CollectionViewCell::~CollectionViewCell()
{
    CC_SAFE_RELEASE(_imageView);
}

CollectionViewCell* CollectionViewCell::create(const char *fileName)
{
    CollectionViewCell* cell = new CollectionViewCell();
    if(cell && cell->init(fileName))
    {
        cell->autorelease();
        return cell;
    }
    CC_SAFE_DELETE(cell);
    return nullptr;
}

bool CollectionViewCell::init(const char *fileName)
{
    this->setImageViewWithFile(fileName);
    return true;
}

void CollectionViewCell::reset()
{
    _idx = -1;
}

ssize_t CollectionViewCell::getIdx() const
{
    return _idx;
}

void CollectionViewCell::setIdx(ssize_t idx)
{
    _idx = idx;
}

void CollectionViewCell::setImageViewWithFile(const char *fileName)
{
    Texture2D *texture2D = Director::getInstance()->getTextureCache()->addImage(fileName);
    _imageView->setTexture(texture2D);
    Size size = texture2D->getContentSize();
    _imageView->setTextureRect(Rect(0, 0, size.width, size.height));
    _imageView->setPosition(Point(size.width*0.5f, size.height*0.5f));
}

Sprite* CollectionViewCell::getImageView()
{
    return _imageView;
}