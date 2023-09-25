#include <iostream>
#include <string>
#include <stdexcept>


// Target interface to adapt
class MediaPlayer {
public:
  virtual void play(std::string format, std::string filename) = 0;
};

// Adaptee interface to be adapted
class MediaPlayerAdvanced {
public:
  virtual void playVideo(std::string filename) = 0;
  virtual void playAudio(std::string filename) = 0;
};

class ConcretePlayerOnlyVideo: public MediaPlayerAdvanced{
public:
  void playAudio(std::string filename) override {
    // Do nothing
  }

  void playVideo(std::string filename) override {
    std::cout << "Playing VIDEO file: " << filename << std::endl; 
  }
};

class ConcretePlayerOnlyAudio: public MediaPlayerAdvanced {
public:
  void playAudio(std::string filename) override {
    std::cout << "Playing AUDIO file: " << filename << std::endl; 
  }

  void playVideo(std::string filename) override {
    // Do nothing
  }
};

// Class Adapter
class MediaAdapter: public MediaPlayer {
public:
  MediaAdapter(std::string format) {
    if (format == "video") {
      mediaPlayerAdvanced_ = new ConcretePlayerOnlyVideo();
    } else if (format == "audio") {
      mediaPlayerAdvanced_ = new ConcretePlayerOnlyAudio();
    } else {
      std::string expt_msg = "Invalid format: " + format;
      throw std::invalid_argument(expt_msg);
    }
  }

  void play(std::string format, std::string filename) override {
    if (format == "video") {
      mediaPlayerAdvanced_->playVideo(filename);
    } else if (format == "audio") {
      mediaPlayerAdvanced_->playAudio(filename);
    } else {
      std::string expt_msg = "Invalid format: " + format;
      throw std::invalid_argument(expt_msg);
    }
  }

private:
  MediaPlayerAdvanced* mediaPlayerAdvanced_;
};

class AudioPlayer: public MediaPlayer {
public:
  void play(std::string format, std::string filename) override {
    if (format == "audio") {
      std::cout << "Playing AUDIO file: " << filename << std::endl; 
    } else if (format == "video") {
      MediaAdapter adapter(format);
      adapter.play(format, filename);
    } else {
      std::string expt_msg = "Invalid format: " + format;
      throw std::invalid_argument(expt_msg);
    }
  }
};

int main () {
  AudioPlayer my_audio_player;

  // Valid media formats
  my_audio_player.play("audio", "this_file.mp3");
  my_audio_player.play("video", "that_file.mp3");

  // Unsupported format
  try {
    my_audio_player.play("graphic", "another_file.mp3");
  } catch (const std::invalid_argument& ex) {
    std::cout << ex.what() << std::endl;
  }

  return 0;
}
