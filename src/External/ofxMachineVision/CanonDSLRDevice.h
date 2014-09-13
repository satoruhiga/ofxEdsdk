#pragma once

#include "ofxEdsdk.h"
#include "../../../addons/ofxMachineVision/src/ofxMachineVision/Device/Updating.h"
namespace ofxMachineVision {
	namespace Device {
		class CanonDSLRDevice : public Updating {
		public:
			CanonDSLRDevice();
			Specification open(int deviceID) override;
			void close() override;
			void singleShot() override;

			void updateIsFrameNew() override;
			bool isFrameNew() override;
			shared_ptr<ofxMachineVision::Frame> getFrame();
		protected:
			int frameIndex;
			ofxMachineVision::Microseconds openTime;
			shared_ptr<ofxEdsdk::Camera> camera;
		};
	}
}