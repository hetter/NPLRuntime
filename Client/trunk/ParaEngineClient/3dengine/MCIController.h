#pragma once

namespace ParaEngine
{

  /** MCI provides applications with device - independent capabilities for controlling audio and visual peripherals.
	* Your application can use MCI to control any supported multimedia device, including waveform - audio devices, 
	* MIDI sequencers, CD audio devices, and digital - video(video playback) devices.
	*
	* Class MCIController wrap MCI commands for you to accomplish certain task(s) much more easier. For instance, 
	* you can record sound from microphone by simply calling three methods: Start(),Stop() and Save(const char* fileName).
	* 
	*/
	class MCIController
	{
	public:
		MCIController();

		~MCIController();

		void Start();

		void Stop();

	  /** Save to the WAV file and close the MCI device as well.
		* @param fileName: full file name with .wav extension.
		*/
		void Save(const char* fileName);
	};

}