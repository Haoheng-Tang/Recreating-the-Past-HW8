#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	grabber.setDeviceID(0);
	grabber.setup(640, 480);

	img.allocate(640, 480, OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){

	grabber.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	grabber.draw(0, 0);
	img.draw(grabber.getWidth(), 0);

	//for (int z = 0; z < 8; z++) {
		for (int i = 0; i < grabber.getHeight()-2; i++) {
			int seeds = int(i*ofGetElapsedTimef()*mouseX*mouseY);
			ofSeedRandom(seeds);
			double noise = ofRandom(0, 10);
			ofColor color;
			if (noise < 5) {
				color = grabber.getPixels().getColor(position, i);
			}
			else if (noise < 6){
				color.set(255, 0, 0);
			}
			else if(noise < 7){
				color.set(0, 255, 0);
			}
			else if (noise < 8)
			{
				color.set(0, 0, 255);
			}
			else
			{
				color.set(0, 0, 0);
			}

			for (int n = 0; n < 20; n++){
				img.setColor(position+n, i, color);
			}

			ofLogNotice() << "The value of noise is: " << noise;
		}
		img.update();

		position = position+20;
		if (position > grabber.getWidth()-20) {
			position = 0;
		} 
	//}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
