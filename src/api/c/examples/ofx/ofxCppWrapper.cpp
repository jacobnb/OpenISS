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

void ofx_setup(){
    
}
void ofx_update()
void ofx_draw()

void ofx_keyPressed(int key)
void ofx_keyReleased(int key)
void ofx_mouseMoved(int x, int y )
void ofx_mouseDragged(int x, int y, int button)
void ofx_mousePressed(int x, int y, int button)
void ofx_mouseReleased(int x, int y, int button)
void ofx_mouseEntered(int x, int y)
void ofx_mouseExited(int x, int y)
void ofx_windowResized(int w, int h)







}