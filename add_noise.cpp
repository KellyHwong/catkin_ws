Mat mSource_Bgr;
mSource_Bgr= imread(FileName_S,1);

double m_NoiseStdDev=10;

Mat mNoise_Bgr = mSource_Bgr.clone();
Mat mGaussian_noise = Mat(mSource_Bgr.size(),CV_8UC3);

randn(mGaussian_noise,0,m_NoiseStdDev);
mNoise_Bgr += mGaussian_noise;

normalize(mNoise_Bgr,mNoise_Bgr,0, 255, CV_MINMAX, CV_8UC3);

imshow("Output Window",mNoise_Bgr);
//imshow("Gaussian Noise",mGaussian_noise);

