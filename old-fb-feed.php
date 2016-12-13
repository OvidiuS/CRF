<a href="https://www.facebook.com/pages/Camps-Firebird-Roosevelt/270670676412">
								<!-- START RSS MODULE -->
								<img src="<?php echo $config->urls->templates?>images/facebook64.png" alt="facebook"/></a>
								<h3>Fresh from Facebook</h3>
								<ul class="freshFromFB">
								<?php 

									$token =  file_get_contents("https://graph.facebook.com/oauth/access_token?client_id=370212483178411&client_secret=71e876eb21f8e72a6497409cdd7b8faa&grant_type=client_credentials");
									//echo file_get_contents("https://graph.facebook.com/v2.2/29598302267/feed?access_token=1451351111833066|CyPzCYU1NBpvPr-FqMpJJ5PjlCg");

									$unparsed_json = file_get_contents("https://graph.facebook.com/v2.2/270670676412/feed?".$token);

									$json_array = json_decode($unparsed_json, true);
									$noOfWordstoShow = 15;
									$i= 0 ; // initialize counter

									foreach ($json_array['data'] as $item_arr) : 
										$postBody = $item_arr["message"] == "" ? $item_arr["story"] : $item_arr["message"];
										?>
										<li>
											<h4>
												<a href="<?= $item_arr['actions'][0]['link']; ?>"><?= date('m/d/Y',strtotime($item_arr["created_time"])); ?></a>
											</h4>
											<?php 
											 if ( str_word_count($postBody) > $noOfWordstoShow) {
											 	echo extractText($postBody, $noOfWordstoShow, "on");
											 }else{
											 	echo $postBody;
											 }
											
											?>
										</li>

									<?php
									$i++; if ($i >= 3 ) {	break; } // set number of posts to list
									endforeach 
									?>

								</ul>
								<!-- END RSS MODULE -->