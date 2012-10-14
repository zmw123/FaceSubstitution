#pragma once

#include "ofMain.h"
#include "ofxFaceTrackerThreaded.h"
#include "Clone.h"
#include "ofxGui.h"
#include "MouthOpenDetector.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void setVideoPosition(float & position);
		void vSyncPressed(bool & pressed);


		ofxFaceTracker faceTracker1, faceTracker2;
		ofxFaceTrackerThreaded threadedFaceTracker1, threadedFaceTracker2;
		ofxFaceTracker *currentFaceTracker1, *currentFaceTracker2;
		ofVideoGrabber grabber;
		ofVideoPlayer player;
		ofBaseVideoDraws * video;
		ofImage half1,half2,half1Src,half2Src;
		ofMesh mesh1, mesh2;
		ofVboMesh combinedMesh;
		MouthOpenDetector mouthOpenDetector1,mouthOpenDetector2;

		bool meshesInitialized;


		bool cloneReady;
		Clone clone1,clone2;
		ofFbo src1Fbo, mask1Fbo;
		ofFbo src2Fbo, mask2Fbo;
		ofPixels maskPixels;
		bool found;

		ofxPanel gui;
		ofParameter<bool> vSync;
		ofParameter<bool> updateOnLessOrientation;
		ofParameter<float> videoPosition;
		ofParameter<bool> showDebug;
		ofParameter<bool> drawMesh1,drawMesh2;
		ofParameter<bool> found1, found2;
		ofParameter<float> noSwapMS;
		ofParameter<float> rampStrenghtMS;
		ofParameter<int> maxStrength;
		ofVec2f lastOrientation1,lastOrientation2;
		bool lastOrientationMouthOpenness1,lastOrientationMouthOpenness2;
		float lastTimeFace;
};
