/*
* Attempt to wrap Protonect for use in C code
* By Jacob Biederman 12-2018
* 
* Following http://blog.eikke.com/index.php/ikke/2005/11/03/using_c_classes_in_c.html
* may have other errors.
*/

#include "ofxCppWrapper.h"
#include "ofxCpp.h"

extern "C" {
ofxC *ofx_new() {
    ofApp *a = new ofApp();
    return (ofxC *)a;
}

void ofx_setup(const ofxC *cOfApp){
  ofApp *a = (ofxC *)cOfApp;
  a->setup();
}
void ofx_update(const ofxC *cOfApp){
    ofApp *a = (ofxC *)cOfApp;
    a->update();
}
void ofx_draw(const ofxC *cOfApp){
    ofApp *a = (ofxC *)cOfApp;
    a->draw();
}

void ofx_keyPressed(const ofxC *cOfApp, int key){
    ofApp *a = (ofxC *)cOfApp;
    a->keyPressed(key);
}
void ofx_keyReleased(const ofxC *cOfApp, int key){
    ofApp *a = (ofxC *)cOfApp;
    a->keyReleased(key);
}
void ofx_mouseMoved(const ofxC *cOfApp, int x, int y ){
    ofApp *a = (ofxC *)cOfApp;
    a->mouseMoved(x, y);
}
void ofx_mouseDragged(const ofxC *cOfApp, int x, int y, int button){
    ofApp *a = (ofxC *)cOfApp;
    a->mouseDragged(x, y, button);
}
void ofx_mousePressed(const ofxC *cOfApp, int x, int y, int button){
    ofApp *a = (ofxC *)cOfApp;
    a->mousePressed(x, y, button);
}
void ofx_mouseReleased(const ofxC *cOfApp, int x, int y, int button){
    ofApp *a = (ofxC *)cOfApp;
    a->mouseReleased(x, y, button);
}
void ofx_mouseEntered(const ofxC *cOfApp, int x, int y){
    ofApp *a = (ofxC *)cOfApp;
    a->mouseEntered(x, y);
}
void ofx_mouseExited(const ofxC *cOfApp, int x, int y){
    ofApp *a = (ofxC *)cOfApp;
    a->mouseExited(x, y);
}
void ofx_windowResized(const ofxC *cOfApp, int w, int h){
    ofApp *a = (ofxC *)cOfApp;
    a->windowResized(w, h);
}
}