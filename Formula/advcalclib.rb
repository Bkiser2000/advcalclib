class Advcalclib < Formula
  desc "Advanced Calculator Library for C++"
  homepage "https://github.com/Bkiser2000/advcalclib"
  url "https://github.com/Bkiser2000/advcalclib/archive/refs/tags/v1.0.0.tar.gz"
  sha256 "6ea3e7b7f5783573a51a1efaac009d601416a2a20399f0538d4d4e568568342a"
  license "MIT"
  
  depends_on "cmake" => :build
  
  def install
    system "cmake", "-B", "build", "-S", ".",
           "-DCMAKE_INSTALL_PREFIX=#{prefix}",
           "-DCMAKE_BUILD_TYPE=Release",
           "-DCMAKE_CXX_FLAGS=-fPIC"
    
    # Build only the library, skip the example
    system "make", "-C", "build", "advcalclib"
    system "cmake", "--install", "build", "--component", "libraries"
    
    # Install headers manually
    include.install Dir["include/*"]
  end
end
