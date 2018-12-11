/*
* Attempt to wrap Protonect for use in C code
* By Jacob Biederman 12-2018
* 
* Following http://blog.eikke.com/index.php/ikke/2005/11/03/using_c_classes_in_c.html
* may have other errors.
*/


typedef void ofxC;
#ifdef __cplusplus
extern "C" {
#endif
ofxC *ofx_new();
void ofx_setup(const ofxC *cOfApp);
void ofx_update(const ofxC *cOfApp);
void ofx_draw(const ofxC *cOfApp);

void ofx_keyPressed(const ofxC *cOfApp, int key);
void ofx_keyReleased(const ofxC *cOfApp, int key);
void ofx_mouseMoved(const ofxC *cOfApp, int x, int y );
void ofx_mouseDragged(const ofxC *cOfApp, int x, int y, int button);
void ofx_mousePressed(const ofxC *cOfApp, int x, int y, int button);
void ofx_mouseReleased(const ofxC *cOfApp, int x, int y, int button);
void ofx_mouseEntered(const ofxC *cOfApp, int x, int y);
void ofx_mouseExited(const ofxC *cOfApp, int x, int y);
void ofx_windowResized(const ofxC *cOfApp, int w, int h);

// Can't wrap these because I'm nut sure what ofDragInfo or ofMessage is
//Probably defined in ofMain.h or an include there, however ofMain.h is AWOL
// void ofx_dragEvent(ofDragInfo dragInfo);
// void ofx_gotMessage(ofMessage msg);

//Same for ofTrueTypeFont
// ofTrueTypeFont  vagRounded;

// These should probably have been wrapped in accessors in c++
// if direct access is needed, they can be wrapped for access in C easily.
// bool    bFullscreen;

// float   ballPositionX;
// float   ballPositionY;
// float   ballVelocityX;
// float   ballVelocityY;

#ifdef __cplusplus
}
#endif
