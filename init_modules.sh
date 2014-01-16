#!/bin/sh

COCOS2D_TAG=cocos2d-x-3.0beta
COCOS2D_REPO=https://github.com/cocos2d/cocos2d-x.git
COCOS2D_DIR=cocos2d

git clone -b ${COCOS2D_TAG} --single-branch --depth 1 ${COCOS2D_REPO} ${COCOS2D_DIR}
git submodule update --init
