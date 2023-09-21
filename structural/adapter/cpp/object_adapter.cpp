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

class MediaAdapter: public MediaPlayer {
public:
  MediaAdapter(std::string format) {
    if (format == "video") {
      mediaPlayerAdvanced_ = new ConcretePlayerOnlyVideo();
    } else if (format == "audio") {
      mediaPlayerAdvanced_ = new ConcretePlayerOnlyAudio();
    } else {
      throw std::invalid_argument("Invalid player format!");
    }
  }

  void play(std::string format, std::string filename) override {
    if (format == "video") {
      mediaPlayerAdvanced_->playVideo(filename);
    } else if (format == "audio") {
      mediaPlayerAdvanced_->playAudio(filename);
    } else {
      throw std::invalid_argument("Invalid player format!");
    }
  }

  ~MediaAdapter() {
    delete mediaPlayerAdvanced_;
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
      throw std::invalid_argument("Invalid player format!");
    }
  }
};

int main () {
  AudioPlayer my_audio_player;

  // Valid media formats
  my_audio_player.play("audio", "this_file.mp3");
  my_audio_player.play("video", "that_file.mp3");

  // Invalid media formats (will throw an exception)
  my_audio_player.play("graphic", "another_file.mp3");

  std::cout << "PRESS ENTER:";
  std::cin.get();
  return 0;
}